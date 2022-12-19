string countAndSay(int n) {
    if(n==1)return "1";
    n=n-1;
    string s1="1",s2="";
    char x=s1[0];
    int c=0;
    for(int i=1;i<=n;i++){
    for(auto s:s1){
        if(s==x)c++;
        else{
            s2.insert(s2.size(),to_string(c)+x);
            c=1;
            x=s;
        }
    }
    s1.clear();
    s2.insert(s2.size(),to_string(c)+x);
    s1=s2;
    c=0;
    x=s1[0];
    if(i!=n)s2.clear();
    }

    return s2;
}