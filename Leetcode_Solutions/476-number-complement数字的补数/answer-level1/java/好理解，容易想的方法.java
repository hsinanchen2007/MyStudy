补码反正一个数与其补码之和为2^n-1（n为位数），所以这样写了，不过肯定没有位运算简单



class Solution {

        public int findComplement(int num) {
            int wei=0;
            int temp=num;
            while(temp!=0)
            {
                temp=temp>>1;
                wei++;
            }
            return (int)(Math.pow(2,wei)-1-num);
        }

}