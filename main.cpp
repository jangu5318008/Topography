#include "Topograph.h"

int main()
{
    string inFileName = "output_USGS30m.asc";
    string outFileName1 = "map.png";
    Topograph topo(inFileName);
    Picture pic(topo.getWidth(), topo.getHeight());
    topo.drawMap(pic);
    pic.save(outFileName1);


    cout << "Width: " << topo.getWidth() << '\n';
    cout << "Height: " << topo.getHeight() << '\n';

    cout << "Minimum: " << topo.getMin() << '\n';
    cout << "Maximum: " << topo.getMax() << '\n';

    return 0;
}
