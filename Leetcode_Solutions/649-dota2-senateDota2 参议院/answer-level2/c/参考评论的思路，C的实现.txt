参考评论的思路，C实现了一版，看着很少有C的题解，就发出来以供参考。
![image.png](https://pic.leetcode-cn.com/c788c04b7fc3d595f936bbe231fab19c48cca2d1938ccf0d99935423b50da489-image.png)

```
char * predictPartyVictory(char * senate){
    int senateLen = 0;
    int ran_ban_dir = 0;
    int dir_ban_ran = 0;
    int cntDire = 0;
    int cntRan = 0;
    char* Radiant = "Radiant";
    char* Dire = "Dire";
    
    if (senate == NULL || strlen(senate) == 0) {
        return NULL;
    }
 
    senateLen = strlen(senate);
    printf("senateLen is %d \n", senateLen);
    if (senateLen < 1 || senateLen > 10000) {
        return NULL;    
    }
    
    while(true) {
        for (int i = 0; i < senateLen; i++) {
            if (senate[i] == 'R' && dir_ban_ran > 0) {
                dir_ban_ran -= 1;
                senate[i] = 'B';
            } else if (senate[i] == 'D' && ran_ban_dir > 0) {
                ran_ban_dir -= 1;
                senate[i] = 'B';  
            } else if (senate[i] == 'R') {
                ran_ban_dir += 1;    
            } else if (senate[i] == 'D') {
                dir_ban_ran += 1;    
            }
        }
        
        printf("senate = %s, ran_ban_dir = %d, dir_ban_ran = %d \n", senate, ran_ban_dir, dir_ban_ran);
        cntRan = 0;
        cntDire = 0;
        for (int i = 0; i < senateLen; i++) {
            if (senate[i] == 'R') {
                cntRan++;        
            } else if (senate[i] == 'D') {
                cntDire++;    
            }
        }
        
        if (cntRan == 0) return Dire;
        if (cntDire == 0) return Radiant;
    } 
}
```
