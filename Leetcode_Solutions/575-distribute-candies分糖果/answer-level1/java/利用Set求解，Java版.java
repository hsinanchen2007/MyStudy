因为数组长度是偶数,两个人最多都能得length/2种糖果，妹妹要尽可能多的种类所以有不重复的优先给妹妹。


```Java []
class Solution {
    public int distributeCandies(int[] candies) {
        Set<Integer> set = new HashSet<Integer>();
        for(int n : candies){
            set.add(n);
        }
        return set.size()>candies.length/2 ? candies.length/2 : set.size();
    }
}
```
