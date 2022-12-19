思路：题目给定了不超过1000个节点，且路径始末不一定是根节点和叶子节点。也即：每个节点都可能成为一段满足答案条件的合法路径。故考虑用一个足够大的数组`Table`表示每个节点，所有数组元素初始化为题设节点值的和`sum`。因为当前有效节点会对含有该节点的所有路径产生影响，所以每层递归中，对所有浅层递归节点对应元素减去当前节点值 `Table[ i ] -= root->val`， 当某一元素被减为0时，说明从 以该元素对应节点开始、到当前节点为止 的路径和满足答案要求，计数器加一 `( *pcnt )++`。

注意：
1.由于每次递归涉及左右两个子树分支，两个子树需要的节点表Table都是一样的（仅经过当前节点及以前节点修改、而不受另一子树节点影响），所以在每层递归结束前，要把节点表Table重写回没有被当前节点影响的状态，也即刚传入的状态 `for( i = 0; i < curSize; i++ ) Table[ i ] += root->val;`。
2。由于树的节点数未知，用一个`curSize`参数表示当前位置之前所含的有效节点个数，每进入一个有效节点累加，每次只对 0 ~ curSize - 1 的Table元素进行操作。

```
int pathSum(struct TreeNode* root, int sum){

    void countPath( struct TreeNode *root, int Table[], int curSize, int *pcnt );

    // initialize the table
    int Table[ 1000 + 10 ] = { 0 };
    int i;
    for( i = 0; i < 1000; i++ )
        Table[ i ] = sum;
    
    // count the answers
    int cnt = 0;
    countPath( root, Table, 0, &cnt );

    return cnt;
}

void countPath( struct TreeNode *root, int Table[], int curSize, int *pcnt )
{
    if( !root )
        return ;

    curSize++;
    int i;
    for( i = 0; i < curSize; i++ )
        if( ( Table[ i ] -= root->val ) == 0 )
            ( *pcnt )++;

    countPath( root->left, Table, curSize, pcnt );
    countPath( root->right, Table, curSize, pcnt );

    for( i = 0; i < curSize; i++ )
        Table[ i ] += root->val;
}
```

还请大家优化指正！
