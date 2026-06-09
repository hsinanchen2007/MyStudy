```
int findLonelyPixel(char** picture, int pictureSize, int* pictureColSize){
    if(pictureSize == 0) {
        return 0;
    }
    if(*pictureColSize == 0) {
        return 0;
    }
    
    int Row = pictureSize;
    int Col = *pictureColSize;
    
    int ans = 0;
    for(int i = 0;i < Row;i++) {
        int count = 0;
        for(int j = 0;j < Col;j++) {
            if(picture[i][j] == 'B') {
                count++;
            }
        }
        if(count == 1) {
            int pos = 0;
            while(picture[i][pos] != 'B') {
                pos++;
            }
            int countB = 0;
            for(int k = 0;k < Row;k++) {
                if(picture[k][pos] == 'B') {
                    countB++;
                }
            }
            if(countB == 1) {
                ans++;
            }
        }
        
    }
    return ans;
}
```
