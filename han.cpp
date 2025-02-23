#include <iostream>
using namespace std;

void vizualization(int**& towers) {
    //cout << towers[0][0] << towers[0][1] << towers[0][2] << endl;
    //cout << towers[1][0] << towers[1][1] << towers[1][2] << endl;
    int height = towers[0][0]+towers[0][1]+towers[0][2];

    for (int i=height+1; i>=0; i--) {
        for (int k=0; k<3; k++){
            for (int j=0;j<(height*2)+1;j++) {
                if (i>0) {
                    
                    if (i>towers[0][k] || i==0) {
                        if (j==height) cout << '|'; else cout << ' '; 
                    }
                    else {
                        if (j==height) cout << '*'; else if (towers[i][k]>=abs(j-height)) cout << '*'; else cout << " ";
                    }
                }
                else cout << "‾"; 
            }
            cout << "\t";
        }
        cout << endl;
    }
    cout << endl;
    return;
}

void debug(int**& towers) {
    cout << endl;
    for (int i=0;i<4; i++) {
        for (int j=0;j<3; j++) {cout << towers[i][j] << " ";}
        cout << endl;
    }
    cout << endl;
}

void han(int**& towers, int n, int start, int point, int temp) {
    if (n != 0) {
        han(towers, n - 1, start, temp, point);

        cout << start << "=>" << point << endl;

        towers[0][point-1]++;
        towers[towers[0][point-1]][point-1]=towers[towers[0][start-1]][start-1];

        towers[towers[0][start-1]][start-1]=0;
        towers[0][start-1]--;

        //debug(towers);
        vizualization(towers);

        han(towers, n - 1, temp, point, start);
    }
    return;
}
int main()
{
    setlocale(LC_ALL, "russian");
    int n;


    while (true) {
        cout << "Введите количество дисков: ";
        cin >> n;
        cout << endl;

        if(n>=0) {
        int** towers = new int*[n+1];
        for(int i = 0; i<n+1 ;i++) towers[i] = new int[3]{};
            for(int i = 1; i<n+1 ;i++) towers[i][0]=n+1-i;
                    towers[0][0] = n;
            vizualization(towers);
            han(towers, n, 1, 3, 2);
        }
    }
    return 0;
}

