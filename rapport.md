# TP 1 Traitement de signal

Remis par :
* Nicolas Hurtubise
* Guillaume Riou

## 1.4

![](image-TpIFT3205-1-4a.png) Cette représentation fréquentielle est associé à l'image D1r. 

On peut voir que l'image a des fortes discontinuités horizontales, ce qui se traduit dans le domaine fréquentiel par des lignes verticales. Une ligne dilatée dans l'axe horizontal spatial sera contractée dans l'axe équivalent spectral et une ligne contractée verticalement au niveau spatial sera dilatée verticalement au niveau spectral.

On déduit aussi la composante verticale des briques par des lignes horizontales dans le domaine fréquentielle mais vu que cette composante verticale est moins forte que la composante horizontale, les lignes horizontales sont moins présentes dans le domaine fréquentiel.

![](image-TpIFT3205-1-4b.png) Cette représentation fréquentielle est associée à l'image D11r puisque cette image se distingue par ses discontinuités verticales entrecoupés par de petites lignes diagonales. On voit dans cette représentation le reflet de l'image avec des directions inversées par le même processus qu'expliqué pour la première image.

![](image-TpIFT3205-1-4c.png) Cette représentation fréquentielle est associée à l'image D46r puisque c'est la seule image à avoir de fortes discontinuités diagonales, ce que l'on voit aussi dans le domaine fréquentiel.

## 3-1

L'image `Monrstein.pgm` est composée des *hautes fréquences* d'un portrait d'Albert Einstein et des *bases fréquences* d'un portrait de Marylin Monroe.

Pour construire cette image, on pourrait faire des opérations similaires à celle réalisée en 2a[1] :

1. Mettre à zéro les basses fréquences de rang `(ε,ε)` de l'image d'Albert Einstein en dessous d'un certain seuil `|ε| <= seuil`
2. Mettre à zéro les hautes fréquences de rang `(ε,ε)` de l'image de Marylin Monroe au-delà d'un certain seuil `|ε| > seuil`
3. Supperposer les deux spectres et faire une transformée de Fourier inverse pour retrouver l'image voulue

On pourrait également se base la distance Euclidienne, comme dans le reste du numéro 2.

On peut noter la présence d'ondulations dans l'image (du *ringing*), ce qui indique que les filtres appliqués créaient effectivement des discontinuités dans le spectre résultant de l'opération.

On pourrait éviter l'effet de *ringing* en utilisant un filtre plus doux, par exemple en utilisant un filtre passe-bas gaussien (plutôt que carré) pour l'image de *Marylin Monroe* et en utilisant le filtre passe-haut gaussien complémentaire sur l'image de *Albert Einstein*.
