### 解题思路
解题思路：
1.将四数之和，转换成三数之和（即拿总和减去第一位数的差）
2.再将三数之和转换成两数之和（即拿第一次的差减去第二位数）
3.设置浮标（浮标的值为第三位和尾数位数的值）
4.进行判断，如果第三位+尾数的值等于第二次的差，那么就添加到集合，如果不是继续遍历。
注：并不需要去跳过相同的元素，去重的操作交给判断hash值来，如果相等则不添加进入集合。如果进行跳过会产生部分答案的丢失。
（这个是参考一些大佬的写法，可惜还是只能写成这样，如果有大佬可以看出可以修改的地方，可以告诉我一下吗？谢谢了，也希望能够帮助到别人）

### 代码

```java
class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        //相等也不做跳过操作
        //排序
        ArrayList<List<Integer>> lists = new ArrayList<>();
        if (nums.length<4){
            return lists;
        }
        Arrays.sort(nums);
        //转换四数为两数
        for (int i = 0; i < nums.length-3; i++) {
            //转换为两数之和
            int onejian = target - nums[i];
            for (int x= i+1;x<nums.length-2;x++){
                //设置双浮标
                //设置首标
                int second = x+1;
                //设置尾标
                int end = nums.length-1;
                //判断当前四个值的值是否相等，若是相等，则直接返回集合
                if (nums[x] == nums[i] && nums[second] == nums[end] && nums[x] == nums[second] && nums[x] ==target){
                    Collections.addAll(lists,Arrays.asList(nums[i],nums[x],nums[second],nums[end]));
                }
                //此处不要进行跳过操作，如果重复的数字，则利用hashcode的值判断集合中是否存在该值
               /* //判断第三个数，与其后一位数之间是否相等，相等则做跳过操作
                if (nums[second] == nums[second+1])second++;*/
                /*//判断尾数与其前面一个数是否相等，若相等则做跳过操作
                if (nums[end] == nums[end-1])end--;*/
                //转换三数之和为两数之和
                int twojian = onejian - nums[x];
                //判断浮标是否超出范围
                while(second<end){
                    //如果两浮标所在的数组元素相加等于两数之和，则做添加操作
                    if (nums[second] + nums[end] == twojian){
                        //重新创建一个新的集合存放当前数据
                        ArrayList<Integer> list = new ArrayList<>();
                        Collections.addAll(list,nums[i],nums[x],nums[second],nums[end]);
                        //判断当前集合是否与已有集合中元素的值重复，若重复则不添加当前存放集合
                        int jishu =0;
                        //比对hash值可以确定是否重复
                        for (int a = 0; a < lists.size(); a++) {
                            if (list.hashCode()!=lists.get(a).hashCode()){
                                jishu++;
                            }
                        }
                        if (jishu == lists.size()){
                            lists.add(list);
                        }
                        //随后进行自增操作继续往后便利
                        second++;
                        end--;
                    }else if(nums[second]+ nums[end] > twojian){
                        //如果两数之和大于第二次的差，那么尾标的值大了，做自减的操作
                        end--;
                    }else{
                        //如果两数之和大于第二次的差，那么首标的值小了，做自增的操作
                        second++;
                    }
                }
            }
        }
        //返回集合
        return lists;
    }
}
```