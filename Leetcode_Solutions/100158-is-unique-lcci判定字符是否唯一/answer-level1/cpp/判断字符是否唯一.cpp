### 解题先对字符串中元素进行排序（冒泡排序），然后设置变量c，赋值字符串第一个元素，最后遍历比较前后元素是否相同即可

### 代码

```cpp
class Solution {
public:
    bool isUnique(string astr) {
        size_t len=astr.size();
        char tmp;
        for(size_t i=0;i<len;++i){                  //冒泡排序
            for(size_t j=0;j<len-i-1;++j){
                if(astr[j]>astr[j+1]){
                    tmp=astr[j];
                    astr[j]=astr[j+1];
                    astr[j+1]=tmp;
                }
            }
        }

        char c=astr[0];
        for(size_t i=1;i<len;++i){
            if(c==astr[i]){
                return false;
            }
            else{
                c=astr[i];
            }
        }

        return true;
    }
};
```