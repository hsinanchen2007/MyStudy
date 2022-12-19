class Solution {
    public int[] twoSum(int[] numbers, int target) {

        int i = 0;//数组头部
        int sum = 0;
        int j = numbers.length - 1;//数组尾部

        //不能让两个标识撞在一起
        while (i<j) {
             sum = numbers[i] + numbers[j];
            if (sum == target) {
                return new int[]{i + 1, j + 1};
            } else if (sum > target) {
                j--;
            } else {
                i++;
            }
        }
        return null;

    }
}
java版本代码，使用这种**双指针**代码要比采用HashMap更加的快速。
之所以可以再这个题目中使用双指针，很重要的原因就在于他是有序列表。
头部的值最小，尾部的值最大。
那么头部移动则必然意味着是增加。
尾部的移动自然是减少。
双指针算法的本质，是将之前的遍历两边列表，得出的可能性。
例子：【1,2,3,4】可能性区间：【1,2】【1,3】【1,4】【2,3】【2，4】【2,5】（命中率1/6）
化成了更小的可能性区间。（因为sum == target并不在乎是哪两个值相加，在乎的是整体值是否相等。）
例子：【1,2,3,4】可能性区间 【3】，【4】 【5】【6】【7】（命中率1/5）
在加上算法本身的特性。搜索效果会大大加强。
HashMap算法
class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int[] a = new int[0];
        HashMap<Integer,Integer> HashMap=new HashMap<>();
        for(int i=0;i<numbers.length;i++){
            HashMap.put(numbers[i],i);
        }
        for(int i=0;i<numbers.length;i++){
            if(HashMap.containsKey(target-numbers[i])){
                return new int []{i+1,HashMap.get(target-numbers[i])+1};
            }
        }
        return a;
    }
}

