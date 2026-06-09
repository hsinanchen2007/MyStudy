n-1次测试排除非候选名人，选出一名候选名人
2(n-1)次验证是否为名人
```
    int findCelebrity(int n) {
        if(n<=1) return 0;
        vector<bool> flag(n, true); //标志候选名人集合
        int cele = 0; //当前假定的候选人
        int count = 0; //排除的候选人的个数
        while(count<n-1){
            for(int i=0; i<n; i++){
                if(i==cele || flag[i]==false) continue;
                if(knows(i, cele)){
                    flag[i] = false;
                    count++;
                }else{
                    flag[cele] = false; count++;
                    cele = -1;
                    for(int k=0; k<n; k++){
                        if(flag[k]==true) {cele=k;break;}
                    }
                    break;
                }
            }
        }
        for(int i=0; i<n; i++){
            if(i!=cele && (knows(i, cele)==false||knows(cele,i)==true) ) return -1;
        }
        return cele;
    }
```