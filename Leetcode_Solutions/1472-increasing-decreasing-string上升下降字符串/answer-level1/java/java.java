 `
```
```
```
       ```
代码块
 StringBuilder stringBuilder=new StringBuilder();
        int[] nums=new int[26];
        for(char c:s.toCharArray()){
             nums[c-'a']++;
        }
        boolean flag;
        do{
            flag=false;
            for(int i=0;i<26;i++){
                if(nums[i]>0){
                    stringBuilder.append((char)(i+'a'));
                    nums[i]--;
                    flag=true;
                }
            }
            for(int j=25;j>=0;j--){
                if(nums[j]>0){
                    stringBuilder.append((char)(j+'a'));
                    nums[j]--;
                    flag=true;
                }
            }
        }while (flag);
        return stringBuilder.toString();
    }
