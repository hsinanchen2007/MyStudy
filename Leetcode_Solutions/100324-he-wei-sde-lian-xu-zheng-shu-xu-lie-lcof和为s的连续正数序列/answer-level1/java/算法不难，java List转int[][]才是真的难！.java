### 解题思路
思路很简单：1.集合类型转化：一个小list存符合条件的等差数列并转化成int[]数组,一个大list存int[]集合，最后把大list转成int[][]数组
2.算法：左指针不动，右指针一直滑，当累加数等于target，把这个List转成int[]加入outer。大于则移动左指针，右指针归零继续滑
最后用outer.toArray(new int[0][])转成二维数组返回。
### 代码

```java
class Solution {
 public int[][] findContinuousSequence(int target) {
        ArrayList<int[]> outer = new ArrayList<>();
        for (int i = 1; i <=target/2 ; i++) {
            ArrayList<Integer> inner = new ArrayList<>();
            int sum = 0 ;
            for (int j = i; j <=target/2+1 ; j++) {
                inner.add(j);
                sum += j;
                if (sum==target){
                    int [] temp  = new int[inner.size()];
                    int x = 0;
                    for (int number : inner) {
                        temp[x] = number;
                        x++;
                    }
                    outer.add(temp);
                    break;
                }else if (sum>target){
                    break;
                }
            }
        }
        int[][] res =  outer.toArray(new int[0][]);
        return res ;
    }
 }
```