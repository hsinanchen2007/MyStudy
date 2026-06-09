int longestPalindrome(string s){
        int ans = 0;
        int num = 58; //a-z 97-122 A-Z 65-90 totally 58 (plus empty)
        short* data = (short*)malloc(num * sizeof(short));
        memset(data, 0, num * sizeof(short));
        short i = 0;
        for(char c : s){
            i = short(c - 'A');
            data[i] += 1;
        }
        bool has_odd = false;
        int res = 0;
        for(short j=0; j < num; j++){
            res = data[j] % 2;
            ans += data[j] - res;
            if(!has_odd && res){
                has_odd = true;
            }
        }
        if(has_odd) ans++;
        free(data);
        return ans;
}