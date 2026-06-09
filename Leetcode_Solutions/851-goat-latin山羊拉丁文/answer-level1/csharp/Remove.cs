public class Solution {
    public string ToGoatLatin(string S) {
        string[] result = S.Split(" ");
        string yuanyin  = "aeiouAEIOU";
        for(int i=0;i<result.Length;i++){
            
            if(yuanyin.IndexOf(result[i][0])!=-1){
                result[i] +="ma";
            }else{
                string temp = result[i][0]+"ma";
                result[i] = result[i].Remove(0, 1)+temp;
            }
            
            int j = i;
            while(j>-1){
                result[i]+="a";
                j--;
            }
            
        }
        
        string sum = "";
        for(int k=0;k<result.Length;k++){
            sum+=(" "+result[k]);
        }
        
        return sum.Remove(0,1);
    }
}