### 解题思路
主要是为了用一下uthash
![image.png](https://pic.leetcode-cn.com/e5118b71fb14393831d1a83fcce9dab15f1725609ffb372bee39f1fdf097f7c0-image.png)

### 代码

```c
#define MY_OK 0
#define MY_FAIL (-1)

struct my_struct {
    int user_id;                    /* key */
    int cnt;
    UT_hash_handle hh;         /* makes this structure hashable */
};

struct my_struct *users = NULL;

int hashUpdate(int id)
{
	struct my_struct *s = NULL;
	HASH_FIND_INT(users, &id, s);
	if (s == NULL) {
		s = (struct my_struct*)calloc(1, sizeof(struct my_struct));
		if (s == NULL) {
			return MY_FAIL;
		}
		s->user_id = id;
		HASH_ADD_INT(users, user_id, s);
	}
	s->cnt++;
	return MY_OK;
}

void hashFree(void)
{
    struct my_struct *current_user, *tmp;

    HASH_ITER(hh, users, current_user, tmp) {
        HASH_DEL(users,current_user);  /* delete it (users advances to next) */
        free(current_user);            /* free it */
    }
}

bool hashChk(void)
{
	int oddcnt = 0;
	struct my_struct *current_user, *tmp;
	HASH_ITER(hh, users, current_user, tmp) {
		//printf("\'%c\' %d\n", (char)current_user->user_id, current_user->cnt);
		if (current_user->cnt % 2 != 0) {
			oddcnt++;
		}
	}
	return oddcnt <= 1;
}
bool canPermutePalindrome(char* s){
	bool rlt;
	while(*s != '\0') {
		hashUpdate(*s);
		s++;
	}
	rlt = hashChk();
	hashFree();
	return rlt;
}
```