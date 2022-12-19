bool isPalindrome(int x){
    long rs=0;//这里系统之前在提示用int会溢出，但是实际上不会溢出。
    int X_2;
    X_2=x;
    if(x<0)
      return false;

    while(x>0){
        rs=rs*10+x%10;
        x=x/10;
    }
    if(rs==X_2)
       return  true;
   else 
       return false;

}