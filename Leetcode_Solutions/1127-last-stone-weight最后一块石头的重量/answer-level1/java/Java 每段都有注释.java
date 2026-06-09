/*
*题目: 1046. 最后一块石头的重量

*描述: 首先进行数组排序，java 默认是从小到大进行排序，，所以while 循环的时候从后往前，每次取出来前两个数，判断是不是完全分解，如果是的话，直接数组长度 -2，，如果不是，那么留个位置给没有粉碎的部分。之后进行数组移动。 
     
     **注意：数组的边界问题， i == 0时、nums - i ==0 时这种情况。**
         
*/

```

class Solution {
    public int lastStoneWeight(int[] stones) {
        int nums = stones.length - 1;
        Arrays.sort(stones); //首先进行排序
        while(nums >= 0){
            if(nums == 0){ //判断是否只剩下一个石头
                return stones[0];
            }
            //else 判断如果有两个及两个以上的石头
            else{
                // a代表最重的石头、b代表其次重的石头、tmp表示a-b,默认是两块石头全部粉碎的情况
                int a = stones[nums], b = stones[nums - 1], tmp = 0; 
                
                // 两块石头重量不相等的情况
                if(a > b){
                    tmp = a - b;
                }

                //将两块用过的石头置为0，tmp已经存了新的重量。（下面这两行也可以不写，为了方便理解)
                stones[nums] = 0;
                stones[nums - 1] = 0;
                
                //如果两个石头都粉碎了，那么直接将数组的下标移动两个位置。
                if(tmp == 0){
                    nums -= 2;
                }

                //如果产生新的石头重量
                else{
                    //将数组进行移动，nums-1而不是nums-2，是因为需要一个位置给新的石头
                    for(int i = nums - 1; i >= 0; i--){

                        //（nums-1） == 0 表示如果只剩一个位置、i == 0 表示如果循环到最后一个位置了（就是这个新产生的石头是这里面重量最小的，那么就排到 i = 0 这个位置）
                        if(nums - 1 == 0 || i == 0){
                            stones[0] = tmp;
                            break;
                        }

                        //如果新的石头比此时比较的石头大或相等，那么就把这个新石头安排在i这个位置
                        else if(tmp >= stones[i - 1]){
                            stones[i] = tmp;
                            break;
                        }

                        //所有石头进行移动
                        stones[i] = stones[i - 1];
                    }
                    //因为有新的石头产生，所以需要留个位置给新的石头，所以数组 -1 就可以了
                    nums--;
                }
            }
        }
        return 0;
    }
}
```

