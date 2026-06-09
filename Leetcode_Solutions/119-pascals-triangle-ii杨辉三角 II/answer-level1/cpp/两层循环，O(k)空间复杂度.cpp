### 解题思路
1、O(k)空间复杂度就是用一个数组完成；
2、那么我们可以认为，除去第一第二层，第三层开始的时候，第一个元素和最后一个元素都是1，中间的某个元素是上一层的相同位置的元素和相同位置前一个元素相加的和；
3、比如，第三层，第一个元素和第三个元素都是1，第二个元素是第二层的第二个元素和第一个元素相加；
###代码思路：
1、除去第一层和第二层的特殊情况；
2、第一层循环是根据rowIndex遍历每一层，第二层循环是获得、更新每一层中的全部元素；
3、进入第二层循环前，都要先获得当前遍历层上一层的第一个和第二个元素，用变量save1和save2存着；
4、第二层循环中，相加得到一个新的数后，要重新获得上一层的相同位置元素及前一个位置元素；
5、每次走完第二层循环都要为当前层末尾加上1

### 代码

```cpp
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result;

        result.push_back(1);
        if(rowIndex == 0) return result;
        result.push_back(1);
        if(rowIndex == 1) return result;

        for(int i = 3; i < rowIndex + 2; i++){
            int save1 = result[0];
            int save2 = result[1];
            for(int j = 0; j < i - 2; j++){
                result[j+1] = save1 + save2;
                if(j != i - 3){
                    save1 = save2;
                    save2 = result[j+2];
                }
            }
            result.push_back(1);
        }
        
        return result;
    }
};
```