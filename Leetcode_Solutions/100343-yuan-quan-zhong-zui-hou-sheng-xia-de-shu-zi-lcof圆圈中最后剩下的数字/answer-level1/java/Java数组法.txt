### 解题思路
1. 先使用一个数组来模拟这个环形的圈
2. index = (index + m -1)%list.size();来使得如果操作了索引上边界就从头开始也就是所谓的环形操作
3. 每次遍历到索引之后将其删除就可以了。当剩下一个元素的时候，终止循环，剩下的那个元素就是我们需要的到的最后一个元素了

### 代码

```java
class Solution {
public int lastRemaining(int n, int m) {
            //使用一个数组来做这个题目话
            List<Integer> list = new ArrayList<>();
            for(int i = 0;i< n; i++){
                list.add(i);//用一个数组来模拟
            }
           
            //遍历刚刚的数组
            int index = 0;
            while (list.size()>1){
                index = (index +m -1)%list.size();
                list.remove(index);

            }
            return list.get(0);
        }

    
}
```