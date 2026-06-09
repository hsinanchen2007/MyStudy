题目中说了全部都是字母，为了解决末尾的情况和全部都是相同字母的情况
我在字符串后面加了一个数字字母，这样就可以用一套程序处理啦啦啦~

`public class Solution {
    public IList<IList<int>> LargeGroupPositions(string S) {
        
        char luis = S[0];
        int preIndex = 0;
        S+="1";
         IList<IList<int>> lisy = new List<IList<int>>();
        
        for(int i=1;i<S.Length;i++){
            
            if(S[i]!=luis){
                if(i-preIndex>=3){
                    IList<int> guis = new List<int>();
                    guis.Add(preIndex);
                    guis.Add(i-1);
                    lisy.Add(guis);
                }
                preIndex = i;
                luis = S[i];
            }
        }
     
       
        
        return lisy;
        
    }
    
}`