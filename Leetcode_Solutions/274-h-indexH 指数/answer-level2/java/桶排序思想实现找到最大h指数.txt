![2020041001.PNG](https://pic.leetcode-cn.com/75d8c0db6c626f849d7fe8dca2f12ccd5413a412f6f5ea8a56d6ea58967b57df-2020041001.PNG)

## 解题思路
1) 声明临时变量max, 声明变量out记录最大的h指数
2) 遍历一遍数组citations, 用临时变量max 记录找到最大的数 
3) 声明长度为(max+1)的数组count, 声明完数组count后, 将max变量置为0, 这里的数组count可视作桶
4) 遍历数组citations, 得到citations的值value, 并在value 对应的数组count的位置++, 即count[value]++
5) 这里count数组的下标索引值表示被引用的次数, count数组的值表示文章数
6) 再从后往前遍历数组count, 寻找到最大的h值, 用max记录遍历到当前位置的总共文章数, 遍历过程中, h指数的两种取值情况
--(1) 当前文章数max <= 引用次数i, 即此时h指数可取值为max, 并且, 若max大于out, 更新Out
--(2) 当前文章数max > 引用次数i, 即此时h指数可取值为i, 并且, 若i大于out, 更新Out
7) 最后返回out
### 代码

```java
class Solution {
    public int hIndex(int[] citations) {
        //遍历一遍数组citations, 找到最大的数 
        int max = 0;
        for(int i=0;i<citations.length;i++){
            if(citations[i]>max){
                max = citations[i];
            }
        }
        //声明长度为(max+1)的数组count
        int[] count = new int[max+1];
        //遍历数组citations, 得到citations的值value, 并在value 对应的数组count的位置++, 即count[value]++
        //这里count的下标索引值表示被引用的次数, count数组的值表示文章数
        for(int i=0;i<citations.length;i++){
            count[citations[i]]++;
        }
        //再从后往前遍历数组count, 寻找到最大的h值
        max = 0;//用max记录遍历到当前位置的总共文章数
        int out = 0;//记录最大的h指数
        for(int i=count.length-1;i>=0;i--){
            if(count[i]!=0){
                max+=count[i];
                if(max<=i&&max>out){//当前文章数max <= 等于引用次数i, 即此时h指数可取值为max, 并且, 若max大于out, 更新Out
                    out = max;
                }else if(max>i&&i>out){//当前文章数max > 等于引用次数i, 即此时h指数可取值为i, 并且, 若i大于out, 更新Out
                    out = i;
                }
            }
        }
        return out;
    }
}
```