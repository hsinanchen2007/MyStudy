提交结果：
执行用时 :4 ms, 在所有 Java 提交中击败了93.42% 的用户
内存消耗 :40 MB, 在所有 Java 提交中击败了90.71%的用户

思路：拿到这道题，想了很多花里胡哨的方法都没有用，去看了一下我全排列1的做法，
加了两三行代码处理相同元素就ok了


代码：
```
public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>>res =new ArrayList<>();//结果集
        Arrays.sort(nums);//先排个序
        List<Integer> list=new ArrayList<>();
        for (int i = 0; i <nums.length; i++) {//转移到列表中，这样有一个好处，我用过了可以直接把他删了
            list.add(nums[i]);
        }
        res.addAll(addElement(new ArrayList<>(),list));//递归调用
        return res;
    }
//    下面这个函数每一次调用处理一位数字，比如我现在放第一位数字，
//    那么nums中的每一个数都一个可以放在这个位置
//    把这个数字安置之后，将其从nums中删除，并进行下一次调用
//    因为这个可能包含相同元素，所以要排除相同的元素都来占位置，
//    我选择先排序，把相同的数字放在一起，第一个相同数放置过，用while循环来跳过剩下的  
    public List<List<Integer>> addElement(List<Integer> last,List<Integer> nums) {
        List<List<Integer>>res =new ArrayList<>();
        if (nums.size()==0){//出口
            res.add(last);
        }
        else if (nums.size()==1){//出口，好像是没有必要两个出口  ，暂时放在这
            List<Integer>tmp=new ArrayList<>(last);
            tmp.add(nums.get(0));
            res.add(tmp);
        }
        else {
            for (int i = 0; i <nums.size(); i++) {
                List<Integer>tmp=new ArrayList<>(last);
                List<Integer> tmp2=new ArrayList<>(nums);//先拷贝一份，不然影响其他人使用
                tmp.add(nums.get(i));
                tmp2.remove(i);
                while (i<nums.size()-1&&nums.get(i+1).equals(nums.get(i)))i++;//排除重复的元素
                res.addAll(addElement(tmp,tmp2));
            }
        }
        return res;
    }
```
