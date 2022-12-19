```
class Solution {
public:
    char blackChar = 'B';
    int findLonelyPixel(vector<vector<char>>& picture) {
        int resultNum = 0;
        map<int,int> nonColumns; // 记录已经确认含有2个及以上的孤独像素的列
        map<int,int> lineMap; // 记录每行已访问的孤独像素个数
        for(int i = 0;i != picture.size();i++){
            if(lineMap[i] > 1)
                continue;
            int bNum = 0; // 记录一行有多少个黑色像素
            int jIndex = 0; // 记录最后一个黑色像素的下标
            for(int j = 0;j != picture[i].size();j++){
                if(picture[i][j] == blackChar)
                {
                    bNum++;
                    if(bNum > 1)
                        break;
                    jIndex = j;
                }
            }
            if(bNum != 1)
                continue;
            else{
                if(nonColumns[jIndex] == 1)
                    continue;
                bNum = 0; // 记录一列有多少个黑色像素
                for(int k = i;k != picture.size();k++){ 
                    if(picture[k][jIndex] == blackChar){
                        bNum++;
                        if(lineMap[k] == NULL)
                            lineMap[k] = 0;
                        lineMap[k]++;
                    }
                    if(bNum > 1)
                        break;
                }
                if(bNum != 1)
                    nonColumns[jIndex] = 1;
                else
                    resultNum++;
            }
        }
        return resultNum;
    }
};
```
