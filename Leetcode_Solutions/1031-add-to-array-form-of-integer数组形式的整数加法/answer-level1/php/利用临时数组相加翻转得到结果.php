1. 关于复杂度
     1.1 时间复杂度为 O(n)
     1.2 空间负责度为 O(n)
2. 我的解题思路
     2.1 将K变成一个整数数组
     2.2 新建一个长度为原两个数组长度较大值+1的数组
     2.3 循环遍历两个数组相加值
     2.4 翻转遍历新建数组得到最终结果


### java实现
```
class Solution{

    /**
     * 1.About Complexity
     *     1.1 Time Complexity is O(n)
     *     1.2 Space Complexity is O(n)
     * 2.how I solve
     *     2.1 turn K to a digit array
     *     2.2 set a array whose length is the bigger of two original array's length plus 1
     *     2.3 circulate two original array to plus value
     *     2.4 reverse the be set array to a list to return
     * 3.About submit record
     *     3.1 13ms and 53MB memory in LeetCode China
     *     3.2 4ms and MB 40.7memory in LeetCode
     * 4.Q&A
     * @param A
     * @param K
     * @return
     */
    public List<Integer> addToArrayForm(int[] A, int K) {
        List<Integer> list=new ArrayList<>();
        int power=1;
        while(K!=0){
            int temp=K%(int)(Math.pow(10,power));
            K-=temp;
            temp=temp/(int)(Math.pow(10,power-1));
            list.add(temp);
            power++;
        }
        int[] nums=new int[A.length>list.size()?A.length+1:list.size()+1];
        int i=A.length-1,j=0,k=0;
        int sum=0;
        while(i>=0||j<list.size()){
            if(i>=0){
                sum+=A[i--];
            }
            if(j<list.size()){
                sum+=list.get(j++);
            }
            if(sum>9){
                nums[k]+=sum%10;
                nums[k+1]+=1;
            }
            else{
                nums[k]+=sum;
            }
            if(nums[k]>9){
                nums[k]=nums[k]%10;
                nums[k+1]+=1;
            }
            k++;
            sum=0;
        }
        List<Integer> res=new ArrayList<>();
        if(nums[nums.length-1]!=0){
            res.add(nums[nums.length-1]);
        }
        for(int l=nums.length-2;l>=0;l--){
            res.add(nums[l]);
        }
        return res;
    }
}

```

### php实现
```
class Solution{

    /**
     * 1.About Complexity
     *     1.1 Time Complexity is O(n)
     *     1.2 Space Complexity is O(n)
     * 2.how I solve
     *     2.1 turn K to a digit array
     *     2.2 set a array whose length is the bigger of two original array's length plus 1
     *     2.3 circulate two original array to plus value
     *     2.4 reverse the be set array to a list to return
     * 3.About submit record
     *     3.1 100ms and 16.8MB memory in LeetCode China
     *     3.2 100ms and 16.5MB memory in LeetCode
     * 4.Q&A
     * @param A
     * @param K
     * @return
     */
    function addToArrayForm($A, $K) {
        $list = [];
        $power = 1;
        while ($K != 0){
            $temp = $K % pow(10, $power);
            $K -= $temp;
            $temp = $temp / pow(10, $power - 1);
            $list[] = $temp;
            $power++;
        }
        $nums = array_fill(0, count($A) > count($list) ? count($A) + 1 : count($list) + 1, 0);
        $i = count($A) - 1;
        $j = 0;
        $k = 0;
        $sum = 0;
        while ($i >= 0 || $j < count($list)){
            if($i >= 0){
                $sum += $A[$i--];
            }
            if($j < count($list)){
                $sum += $list[$j++];
            }
            if($sum > 9){
                $nums[$k] += $sum % 10;
                $nums[$k + 1] += 1;
            }
            else{
                $nums[$k] += $sum;
            }
            if($nums[$k] > 9){
                $nums[$k] = $nums[$k] % 10;
                $nums[$k + 1] += 1;
            }
            $k++;
            $sum = 0;
        }
        $res = [];
        if($nums[count($nums) - 1] != 0){
            $res[] = $nums[count($nums) - 1];
        }
        for($index = count($nums) - 2; $index >= 0; $index--){
            $res[] = $nums[$index];
        }
        return $res;
    }
}
```
<br />
如果你有更好的想法或者疑问，可以到 [我的leetcode解法仓库](https://github.com/cartoonYu/LeetCodeSolution) 提出issue，我会及时处理
你也可以关注 [我的leetcode解法仓库](https://github.com/cartoonYu/LeetCodeSolution) 获得其他题目解题思路
