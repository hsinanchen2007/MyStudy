### 解题思路
思路是 只要遍历一遍String,然后当出现3个或以上相似时就保存起来（需要到结束的位置）

特殊情况：当所有字母都是一样的时候，例如："aaaaaa"，这样可以在原String上加一个大写字母（来避免特殊情况的判断）。

还需要注意的是：List<List<Integer>>加的是List<Integer>，而List<Integer>也是使用add方法添加元素

注意：我开始是使用toCharArray来转化String，但String方法也可以用charAt方法获得特定的元素。

### 代码

```java
class Solution {
    public List<List<Integer>> largeGroupPositions(String S) {
        S = S + 'A';
        List<List<Integer>> ans = new ArrayList<>();

        int count = 0;
        for(int i = 1; i < S.length(); i++){
            if(S.charAt(i) != S.charAt(i - 1)){
                if(i - count >= 3){
                    List<Integer> tempArray = new ArrayList<>();
                    tempArray.add(count);
                    tempArray.add(i - 1);
                    ans.add(tempArray);
                }
                count = i;
            }
        }

        return ans;
    }
}
```