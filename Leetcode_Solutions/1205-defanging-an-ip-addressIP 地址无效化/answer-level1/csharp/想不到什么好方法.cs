public class Solution {
    public string DefangIPaddr(string address) {
        char[] str=address.ToCharArray();
        string str2="";
        foreach(var item in str){
            if(item=='.'){
                str2+="[.]";
            }else{
                str2+=item;
            }

        }
        return str2;
    }
}