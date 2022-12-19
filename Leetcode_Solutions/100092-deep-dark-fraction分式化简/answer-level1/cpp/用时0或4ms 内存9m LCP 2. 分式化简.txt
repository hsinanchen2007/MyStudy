原理 ai +1/a(i+1) = ai*a(i+1)+1/a(i+1)

推广 ai + 分子/分母 = ai*分母+分子/分母

每轮计算都是在计算分母，在进入下一轮计算前分子分母要换位置

所有轮计算完毕后，分子分母多交换了一次

用时0或4ms 内存9m
```
vector<int> fraction(vector<int>& cont) {
        // 每一次都是a与一个分数相加，且进行下一次相加时分子分母要调换位置。
      
        int son =0;
        int mom =1;
        for(int i=cont.size()-1;i>=0;i--){
            //计算
            son=cont[i]*mom+son;
            //交换分子分母
            cont[i]=son;
            son=mom;
            mom=cont[i];
            //
            cont.pop_back();
        }
        //for 最后一次操作时分子分母多换了一次，最后没有分子1 不需要换位
        cont.push_back(mom);
        cont.push_back(son);
        return cont;
    }
```
