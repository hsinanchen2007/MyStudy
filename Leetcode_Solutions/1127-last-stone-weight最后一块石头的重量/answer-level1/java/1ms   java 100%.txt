用到排序，由于java数组长度固定无法删除元素，所以新建一个变量length指针，粉碎石头就用length--或者length-=2来代替，不需要对粉碎的元素进行任何操作，由于每趟都排序，所以粉碎掉的石头一定在数组的最后面，不会影响
class Solution {
    public int lastStoneWeight(int[] stones) {
        int length=stones.length;
        while(length>=2){
          Arrays.sort(stones);
          if(stones[length-2]==stones[length-1])
              length-=2;
            else{
                stones[length-2]=stones[length-1]-stones[length-2];
                length--;
                
            }
        }
        if(length==1) return stones[0];
        else return 0;
    }
}