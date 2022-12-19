class Solution {
public:
    bool isPerfectSquare(int num) {
if(num==1){
    return true;
}
if(num>=2147483647)
return false;

for(int i=0;i<=num/2;i++){
    if(i*i==num){
return true;
    break;
    } 
}
 return false;
    }
};