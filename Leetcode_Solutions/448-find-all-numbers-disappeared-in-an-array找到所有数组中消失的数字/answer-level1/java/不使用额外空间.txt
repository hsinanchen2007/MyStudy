其实逻辑说简单也简单。j是判断应该到了哪个数字。i是判断遍历到哪个数字。如果碰到相同的直接跳过，如果是正常的j正常++。如果遇到不是重复但是也不是应该有的数字说明这块有缺的了，先添加到list中，然后让j正常++。但是i得--这样下一次遍历还是判断这个数字是不是下一个。自觉哪怕是连着却的数字也能发现。
```
class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        Arrays.sort(nums);
        int j = 1;
        List<Integer> res = new ArrayList<Integer>();
        for(int i = 0;i<nums.length;i++){
            if(nums[i]==j){
                j++;
            }else if(i!=0 &&nums[i]==nums[i-1]){
                continue;
            }else{
                res.add(j);
                i --;
                j ++;
            }
        }
        for(int k = j;k<=nums.length;k++){
            res.add(k);
        }
        return res;
    }
}
```
注：我这个性能并不怎么好，但是起码标准意义的没使用额外空间。
看了好几页题解，性能好的用了额外空间，还有的直接说的都是错的，也是醉了，不自己跑跑再写题解？
因为确实前三页都没看到java不适用额外空间的解法，所以献丑了，有更好方法的大大欢迎交流。