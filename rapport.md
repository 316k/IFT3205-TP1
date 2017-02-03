#Tp 1 Traitement de signal
##Remis par Nicolas Hurtubise et Guillaume Riou

###1

### 3-1

L'image `Monrstein.pgm` est composée des *hautes fréquences* d'un portrait d'Albert Einstein et des *bases fréquences* d'un portrait de Marylin Monroe.

Pour construire cette image, on pourrait faire des opérations similaires à celle réalisée en 2a[1] :

1. Mettre à zéro les basses fréquences de rang `(ε,ε)` de l'image d'Albert Einstein en dessous d'un certain seuil `|ε| <= seuil`
2. Mettre à zéro les hautes fréquences de rang `(ε,ε)` de l'image de Marylin Monroe au-delà d'un certain seuil `|ε| > seuil`
3. Supperposer les deux spectres et faire une transformée de Fourier inverse pour retrouver l'image voulue

On pourrait également se base la distance Euclidienne, comme dans le reste du numéro 2.

On peut noter la présence d'ondulations dans l'image (du *ringing*), ce qui indique que les filtres appliqués créaient effectivement des discontinuités dans le spectre résultant de l'opération.

