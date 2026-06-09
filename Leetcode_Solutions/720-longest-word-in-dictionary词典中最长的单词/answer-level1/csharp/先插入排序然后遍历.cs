C#的字符串数组没有排序的方法，自己手撸了一个插入排序。
```
public class Solution {
    public string LongestWord(string[] words) {
    
        List<string> result = new List<string>();
        
        for (int i = 1; i < words.Length; i++)
        {
            for (int j = i; j >= 1&&words[j].Length < words[j - 1].Length;)
            {
                Swap(j, --j, words);
            }
        }
        
        for(int y = 0; y<words.Length;y++){
            result.Add(words[y]);
        }
        
        bool isRight = true, isFirst = true;
        string max = "";
        
        for(int k=result.Count-1;k>=0;k--){
            
             isRight = true;
                 
            for(int n=result[k].Length-1;n>0;n--){
                
                if(!result.Contains(words[k].Substring(0,n))){
                    isRight = false;
                    break;
                }
            }
                   
            if(isRight == true){
                
                if(isFirst){
                    max = result[k];
                    isFirst = false;
                }
                
                if(result[k].Length==max.Length){
                    
                    for(int h = 0;h<result[k].Length;h++){
                        
                        if(result[k][h]==max[h]){
                          continue;
                        }else{
                            max = result[k][h]>max[h]?max:result[k];
                            break;
                        }
                    }
                }
            }
        }
        
         return max;
    }
      
    
    public void Swap(int i, int j, string[] words ){
        string temp = words[i];
        words[i] = words[j];
        words[j] = temp;
    }
}
```
