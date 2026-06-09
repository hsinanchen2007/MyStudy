public int[] numSmallerByFrequency(String[] queries, String[] words) {
        int[] nums = new int[11];       //字符串的长度在1到10
        int[] answer = new int[queries.length];    
        for(int i=0;i<words.length;i++){         //nums[i]存储words中长度为i的字符串个数
            nums[f(words[i])]++;
        }
        for(int k=9;k>0;k--){           //为了方便后面的查询,nums[i]存储大于等于长度为i的字符串个数
            nums[k]+=nums[k+1];
        }
        for(int j=0;j<queries.length;j++){
            int n = f(queries[j]);       
            if(n==10){
                answer[j]=0;
            }else{
                answer[j]=nums[n+1];
            }
        }
        return answer;
    }
    public int f(String s){           //f函数
        int count=1;
        char ch1=s.charAt(0);
        for(int i=1;i<s.length();i++){
            char ch2=s.charAt(i);
            if(ch1==ch2){
                count++;
            }else if(ch2-ch1<0){
                ch1=ch2;
                count=1;
            }
        }
        return count;
    }