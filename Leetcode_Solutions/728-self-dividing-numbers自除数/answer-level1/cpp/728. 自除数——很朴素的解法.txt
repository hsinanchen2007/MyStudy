```
vector<int> selfDividingNumbers(int left, int right) {
        vector<int>res;
        for(int i=left;i<=right;i++){
            bool isOk = true;
            int temp = i;
            while(temp){
                if(temp%10 == 0 || i%(temp%10) != 0){
                    isOk = false;
                    break;
                }
                temp = temp/10;
            }
            if(isOk == false){
                continue;
            }
            else{
                res.push_back(i);
            }
        }
        return res;
    }
```
