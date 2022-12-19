速度有点慢，但省内存。
先用一个flag[1000]数组保存用户指向及状态，初始化为-1.
遍历一遍accounts，得到一个map<string, vector<int>> mp  ，这个mp里以邮箱地址为映射，保存邮箱对应的用户序号。在遍历的过程中，顺手更新flag，应用并查集即可。
再遍历一遍mp，将邮箱一个个加到对应根用户名下，用一个  map<int, vector<string>> temp保存根节点名下的邮箱，最后将temp挂到ans中，再排序一遍就行了




```
int flag[1000];//flag保存用户指向及状态。这里用指针数组将flag传递到find函数中内存会更少，但是嫌弃太麻烦了
int find(int x) {//查操作

    if (flag[x] != x && flag[x] != -1)//假如不指向自身，flag[x]=x或-1就代表着他是根节点
    {
        return find(flag[x]);
    }

    else
    {
        return x;
    }

}


int main() {
    map<string, vector<int>> mp;
    vector<vector<string>> ans;
    for (int i = 0; i < accounts.size(); i++) {
        flag[i] = -1;//初始化，-1为不重复用户
    }

    for (int i = 0; i < accounts.size(); i++)
    {
        for (int j = 1; j < accounts[i].size(); j++)
        {
            //for循环遍历每个邮箱。建立每个邮箱对应的用户列表
            mp[accounts[i][j]].push_back(i);//加入 该邮箱对应的用户 列表
            int firstuser = mp[accounts[i][j]][0];

            if (mp[accounts[i][j]].size() > 1) {
                if (mp[accounts[i][j]].size() == 2 && (flag[firstuser] == -1))flag[firstuser] = firstuser;//将 对应用户列表 中用户数大于1的邮箱的首用户指向首用户他本身，即指为根用户,本操作仅当列表中有两个用户并且该首用户未指向根用户时执行
                if (flag[i] == -1)flag[i] = find(firstuser);//如果刚加入的用户之前从未被认定为重复用户，将他指向首用户，也就是一次并查集中的并操作。
                else
                {
                    flag[find(flag[firstuser])] = find(flag[i]);//否则，说明该刚加入的用户之前已被指向其他用户，是一个人名下的重复用户。假设已经指向了用户序号X，于是将本邮箱的首用户指向X 。第二次并操作。这里不能是指向firstuser，例如原来firstuser=0，f[0]=1，i=3，f[3]=0.现在要将firstuser指向f[i]，很容易就造成了f[0]指向0，实际上应该是f[0]指向1.需要两者都用一遍find找到根节点，改变其中一个根节点指向来进行并操作
                }
            }
        }
    }
    map<string, vector<int>>::iterator it = mp.begin();
    map<int, vector<string>> temp;
    while (it != mp.end()) {

        //现在我们找到一个邮箱了，我们接下来需要将该邮箱挂到对应自然人的名下
        int root = find(it->second[0]);//根用户
        if (temp[root].size() == 0) {
            temp[root].push_back(accounts[root][0]);
        }//如果根用户还没加入

            temp[root].push_back(it->first);
        
        it++;
    }
    map<int, vector<string>>::iterator single_ans = temp.begin();
    while (single_ans != temp.end()) {
        ans.push_back(single_ans->second);
        single_ans++;
    }
    for (int i = 0; i < ans.size(); i++) {
        sort(ans[i].begin() + 1, ans[i].end());//排序，这一点很坑，一开始以为是按account中的出现顺序排序
    }


 }
```
