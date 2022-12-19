时间复杂度上优于99%
对字符串函数不太熟悉，没有想到转化为字符串，用最笨的方法除以10，转化成的数组，所以空间复杂度只有50%
用到了arraylist（可以顺便熟悉下arraylist中的常用函数）
设2736在数组n里是[2,7,3,6],核心思想是n[i]的值应该是第i+1大的数(最高位的数最大)
** if（符合）continue；
**else{swap（i，第i+1大的数出现的位置）}

考虑到sort()之后是从小到大遍历，所以对于上述数组n是存成的[6,3,7,2];
代码的注释里以[2,7,3,6]为例进行了说明
```
class Solution {
    public int maximumSwap(int num) {
        //假设输入num=2736
        ArrayList<Integer> nums = new ArrayList<>();//要查找位置
        int wei = 0; //num的位数
        while(num > 0){
            int yushu = num % 10;
            num = num / 10;
            nums.add(yushu);//反向存，符合sort由小到大的排序（把原数组和应该递减的两个数组都反过来了）
            wei++;
      }
        //nums为[6,3,7,2]
        //建立用来比较的数组.复制并排序
        int[] sorted = new int[wei];
        for(int i = 0; i < nums.size(); i++){
            sorted[i] = nums.get(i);
        }
        Arrays.sort(sorted);
        //sorted为[2,3,6,7]
       //反着存，所以从后遍历
        for(int i = nums.size()-1; i>=0; i--){
           if(sorted[i] == nums.get(i))
               continue;
           //System.out.println(sorted[i]);
           int tmp = nums.get(i); //tmp=2
           int j = nums.indexOf(sorted[i]);//存要与i位置交换的数出现的位置（7的位置)
           nums.set(i,sorted[i]);//更正i位置为sorted[i]
           nums.set(j,tmp);//将原来7的位置改为2
           break;
       }
        //遍历，将数组转换为数
       int res = 0;
       for(int i = nums.size()-1; i>=0; i--){   
           int t=nums.get(i);
           res=res+t;
           res=res*10;
       }
       return res/10;
   }
}
```
代码在转化成数组，和数组转化成数的时候应该还有可以优化的地方~
