126/126 cases passed (124 ms)
Your runtime beats 53.85 % of csharp submissions
Your memory usage beats 19.05 % of csharp submissions (27.1 MB)
没考虑优化的一种可行方法
using System.Collections.Generic;

public class Solution {
    public bool CanConstruct(string ransomNote, string magazine) {
        char[] m=magazine.ToCharArray();
        Dictionary<char,int> dictionary=new Dictionary<char, int>();
        for(int i=0;i<m.Length;i++){
             if(dictionary.ContainsKey(m[i])){
                 dictionary[m[i]]=dictionary[m[i]]+1;
             }
             else{
                 dictionary.Add(m[i],1);
             }
        }
        char[] r=ransomNote.ToCharArray();
        bool flag=true;
        for(int j=0;j<r.Length;j++){
              if(dictionary.ContainsKey(r[j])){
                  dictionary[r[j]]=dictionary[r[j]]-1;
                  if(dictionary[r[j]]<0){
                      flag=false;
                      break;
                  }
              }
              else{
                  flag=false;
                  break;
              }
        }
        return flag;

    }
}