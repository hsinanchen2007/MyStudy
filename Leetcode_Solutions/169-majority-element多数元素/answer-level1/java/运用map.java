### 解题思路
遍历数组，将数组的值当作key放到map中，值出现的次数当作value，当某一个value值达到n/2时就返回该值

### 代码

```java
class Solution {
    public int majorityElement(int[] nums) {
        int n = nums.length/2;
        Map<Integer,Integer> res = new HashMap<>();
        for (int num : nums) {
            /**
             * 已经存在就取出值加一
             */
            if (res.containsKey(num)) {
                res.put(num,res.get(num)+1);
            }else{
                res.put(num,1);
            }
            if(res.get(num)>n)return num;
        }
        return -1;
    }
}
```