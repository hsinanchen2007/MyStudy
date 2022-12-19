### 解题思路
官方答案中的：先转置再换列。
### 知识点
通过观察图像发现其中的数学规律，大大简化了做法。
### 感悟
害，又是一个通过数学知识来做的题。记得自己做的上一个通过数学知识解的是“只出现一次的数字”。
发现自己在做题的时候总会陷入一种固定的思想：上来我就想怎么旋转每一个元素，坐标之间有什么样的规律。但本题能和转置联系起来，我觉得挺妙的。
下次再遇到这种矩阵转换、旋转的题，得多开动开动脑瓜了。
### 代码

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //采用官方答案先转置，再换列的做法。
        int i,j,tmp;
        int length=matrix[0].size();
        //转置
        for(i=0;i<length-1;i++){
            for(j=i+1;j<length;j++){
                tmp=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=tmp;
            }
        }

        //换列
        for(i=0;i<length;i++){
            for(j=0;j<length/2;j++){
                tmp=matrix[i][j];
                matrix[i][j]=matrix[i][length-1-j];
                matrix[i][length-1-j]=tmp;
            }
        }
    }
};
```