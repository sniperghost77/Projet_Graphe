#include "grman/grman.h"
#include <iostream>

#include "graph.h"

int main()
{
    /// A appeler en 1er avant d'instancier des objets graphiques etc...
    grman::init();



    BITMAP *buffer;
    BITMAP *fd;
    BITMAP*fdinst;
    BITMAP *menu;
    int x = 0;

    buffer=create_bitmap(1024,768);
    fdinst=load_bitmap("fond-marin.bmp",NULL);
    clear_bitmap(buffer);
    fd=load_bitmap("fond.bmp",NULL);



    while(!x)
    {
    clear_bitmap(buffer);
    blit(fd, buffer, 0,0,0,0,1024,768);
  //  masked_blit(menu, buffer, 0,0,0,0, 1024, 768);
    blit(buffer, screen, 0,0,0,0, 1024, 768);

        if ((mouse_b&1))
        {
            if (mouse_y>150 && mouse_y<200)
            {
                clear_bitmap(buffer);
                blit(buffer, screen, 0,0,0,0,1024, 768);
                 grman::set_pictures_path("image");

    /// Un exemple de graphe
    Graph g;
    g.dessiner_graphe();
                while ( !key[KEY_ESC] )
    {
        /// Il faut appeler les méthodes d'update des objets qui comportent des widgets
        g.update();

        /// Mise à jour générale (clavier/souris/buffer etc...)
        grman::mettre_a_jour();
    }
    g.sauv_graph();
                rest(20);
            }
            else if (mouse_y>280 && mouse_y<330)
            {
                clear_bitmap(buffer);

                blit(fdinst, screen, 0,0,0,0,1024, 768);
                rest(1000);
                while(!(mouse_b & 1))
                {

                }
                rest(500);
            }

            else if (mouse_y>410 && mouse_y<460)
            {
                clear_bitmap(buffer);
                x=1;
            }
        }
    }


    /// Le nom du répertoire où se trouvent les images à charger



    /// Vous gardez la main sur la "boucle de jeu"
    /// ( contrairement à des frameworks plus avancés )

    grman::fermer_allegro();

    return 0;
}
END_OF_MAIN();


