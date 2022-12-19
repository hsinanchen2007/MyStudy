### 解题思路
1. 暴力解，每个都遍历   时间复杂度 O(n²)
   暴力解，提交后，通过了73个例子，lc搞了一个两万的数组，直接超出时间限制了
2. 看了官方题解，先将每个年龄一样的划入一个组，再执行组与组直接的判断，可加则按数量相乘
3. 题目中的三个判断条件，有一个是多余的 age[B] > age[A] 和 age[B] > 100 && age[A] < 100
4. b > 100 && a < 100  那么必然是 b > a ,只判断这个就好了

### 代码

```java
class Solution {
    public int numFriendRequests(int[] ages) {
        int[] groups = new int[121];
        for (int i = 0; i < ages.length; i++) {
            groups[ages[i]]++;
        }
        int sum = 0;
        for (int i = 1; i < groups.length; i++) {
            for (int j = i; j < groups.length ; j++) {
                if (addFriend(j,i) || addFriend(i,j)){
                    sum = sum + groups[i] * groups[j];
                    if (i == j){
                        sum = sum - groups[i];
                    }
                }
            }
        }
        return sum;
    }
    private boolean addFriend(int A , int B) {
        return !(B <= 0.5 * A + 7) && B <= A ;
    }
}
```