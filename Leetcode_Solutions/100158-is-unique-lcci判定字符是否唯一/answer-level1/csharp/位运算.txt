public class Solution {
    public bool IsUnique(string astr) {
        int mark=0;
        foreach(var c in astr){
            var item=1<<c;
            if((item&mark)==item)return false;
            mark^=item;
        }
        return true;
    }
}