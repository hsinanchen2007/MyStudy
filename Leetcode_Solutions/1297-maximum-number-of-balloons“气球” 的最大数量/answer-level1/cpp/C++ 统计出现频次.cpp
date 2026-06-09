![image.png](https://pic.leetcode-cn.com/c17b9bcfc3428ce3bf11e0584bd224fd791ced895f6b6a8053982f94d1411ce3-image.png)
解题思路:统计每种字母出现的次数，除以该字母在balloon中出现的次数，取最小值。
```
    int maxNumberOfBalloons(string text) {
        int cnum[5] = {0}; int min = 10000;
        for(int i = 0;i<text.size();++i){
        switch(text[i]){
            case 'a': ++cnum[0];break;case 'b': ++cnum[1];break;case 'l': ++cnum[2];break;
            case 'n': ++cnum[3];break;case 'o': ++cnum[4];break;default :break;break;
                       }
           }
           cnum[2] /= 2;cnum[4] /= 2;
        for(int j = 0;j<5;++j){
            if(cnum[j]<min) min = cnum[j];
        }
        return min;
    }
```

