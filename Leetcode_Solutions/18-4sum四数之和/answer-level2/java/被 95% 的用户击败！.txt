通篇可以说是简单易懂，非常适合初学者。
逻辑清晰，完全不乱！

搭嘎啦！

被95%的大佬击败了！！！


public class fourNumSum {
    public List<List<Integer>> fourSum(int[] nums, int target) {
 **//建立一个空array，ttl意思是“total”，总输出**        
        List<List<Integer>> ttl = new ArrayList<>();        

**//第一个数字的index循环**
        for (int i = 0; i < nums.length; i++)           
        {

**//第二个数字的index循环（从第i个数字的下一个开始循环，因此上限值要“-i”）**
            for (int j = 1; j < (nums.length-i); j++)         
            {

**//第三个数字的index循环（从第i+j个数字的下一个开始循环，因此上限值要“-i”再“-j”）**
                for (int k = 1; k < (nums.length-i-j); k++) 
                {

**//第四个数字的index循环（从第i+j+l个数字的下一个开始循环，因此上限值要“-i”、“-j”再“-l”）**
                    for (int l = 1; l <(nums.length-i-j-k); l++)
                    {

**//求和**
                        int sum = 0;
                        sum = nums[i] + nums[i+j] + nums[i+j+k] + nums[i+j+k+l];

**//如果所得的和，等于目标值，那么就将这四个数打包为一个名为“sub”的List，直接加入另一个List —— 即“ttl”**
                        if (sum == target)
                        {
                            List<Integer> sub = new ArrayList<>();
                            sub.add(nums[i]);
                            sub.add(nums[i+j]);
                            sub.add(nums[i+j+k]);
                            sub.add(nums[i+j+k+l]);
                            ttl.add(sub);

**//调用冒泡算法（在这个方法下面，是另一个自己写的方法），遍历“ttl”中的每个子List，拿出每个子List进行大小排序，同时也要对“sub”进行大小排序，然后比较二者是否完全一致**
                            fourNumSum bubble = new fourNumSum();
                            for (int loop = 0; loop < (ttl.size()-1); loop++)
                            {

**//如果某个“ttl”中的字List在排序后，与“sub”排序后完全一致，那么说明，二者的元素完全相同，需要再将刚刚加入“ttl”中的“sub”从表的末尾删去**
                                if (bubble.sort(sub).equals(bubble.sort(ttl.get(loop))))
                                {
                                    ttl.remove(ttl.size()-1);
                                }
                            }
                        }
                    }
                }
            }
        }
        return ttl;
    }

**//冒泡算法**
    public List<Integer> sort(List<Integer> input){

**//外部计数。用于循环地对该数列进行冒泡算法，次数上限为该数列的长度**
        for (int outterCounter = 0; outterCounter < input.size(); outterCounter++) {

**//由于每次遍历循环数列的所有元素后，该数列的最大值一定会跑到数列的末尾，因此进行下一轮冒泡时，需要将最后一位减掉**
            for (int counter = 0; counter < (input.size() - outterCounter); counter++) {
                if (counter < input.size()-1)
                {

**//如果一个数比它的下一个数要大，那么就把这个数的值赋给一个临时值“temp”**
                    if (input.get(counter) > input.get(counter+1)) {
                        int temp = 0;
                        temp = input.get(counter);

**//然后将后一个数的值赋给这个数，再将“temp”的值赋给后一个数**
                        input.set(counter, input.get(counter+1));
                        input.set(counter+1, temp);
                    }
                }
            }
        }
        return input;
    }
}