
```
public int candy(int[] ratings) {
        //基本思路是，如果前边的部分已经确定，那么从元素cur开始之后的糖果分配
        //不受前边部分的影响，可以将分数划分为连续的上升、下降、持平，三种情况
        //因为每次只会进入一个循环，故时间复杂度为O（n）
        int len = ratings.length;
        if (len < 2)
            return len;
        int cur = 0,result = 0;
        int[] res = new int[len];
        Arrays.fill(res,1);
        while (cur < len){
            int i = 0,j = 0,k = 0;
            //连续上升时
            while (cur+i+1 < len && ratings[cur+i] < ratings[cur+i+1]) i++;
            for (int i_ = 0;i != 0 && i_ <= i;i_++){
                res[cur+i_] = i_+1;
            }
            //连续下降趋势时
            while (cur+j+1 < len && ratings[cur+j] > ratings[cur+j+1]) j++;
            for (int j_ = 0;j != 0 && j_ <= j;j_++){
                res[cur+j_] = j+1-j_;
            }
            //连续持平时
            while (cur+k+1 < len && ratings[cur+k] == ratings[cur+k+1]){
                res[cur+k] = 1;
                k++;
            }
            //根据不同的情况要跳转到不同的位置
            if (i != 0){
                //连续上升情况下，cur到cur+i已经是一个递增的1,2,3...i+1，所以从cur+i+1开始计算
                cur += i+1;
            }else if (j != 0 || k != 0){
                //连续下降情况下，为了避免V型的谷底在下一次迭代中被跳过，需要下一次迭代从谷底开始
                //连续持平的情况下，为了避免最后一个元素恰好是下次连续下降的开头，需要从最后一个元素开始
                //两种情况下，都需要从最后一个元素开始迭代
                cur += j + k;
            }else {
                break;
            }
        }

        for (int v: res){
            result += v;
        }
        //最难以在上述迭代中解决的是Λ型问题，因为如果在第一次连续上升的迭代中为峰顶元素设置的值小于连续下降的迭代次数
        //那么峰顶元素最终不满足大于相邻元素；
        //上述情况同样可以从最后一个元素开始下一次迭代，但是反过来考虑，如果第一次连续上升的迭代中峰顶元素的值大于连续下降的迭代次数，
        //那么这种迭代方式反而又不满足条件
        //故只能在外层进行检查
        for (int i = 1;i < len-1;i++){
            if (ratings[i] > ratings[i-1] && ratings[i] > ratings[i+1] && res[i-1] < res[i+1]){
                result += res[i+1]-res[i-1];
            }
        }

        return result;
    }
```
