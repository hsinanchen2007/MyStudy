### 解题思路哈哈哈

### 代码

```c
typedef struct 
{
	int num_val;
	int val1[1024];
	int count;
	
} CustomStack;


CustomStack* customStackCreate(int maxSize) 
{
	CustomStack *p = (CustomStack *)malloc(sizeof(CustomStack));
	
	p->num_val = maxSize;
	p->count = 0;

	return p;

}

void customStackPush(CustomStack* obj, int x) 
{
	
	if(obj->count >= obj->num_val)
	return;
	
	(obj->val1)[obj->count] = x;
	
	obj->count += 1; 
}

int customStackPop(CustomStack* obj) 
{
	if(obj->count == 0)
	return -1;
	
	int n = (obj->val1)[obj->count - 1];
	obj->count--;
	
	return n;
}

void customStackIncrement(CustomStack* obj, int k, int val)
{
	int i = 0;
	
	if(obj->count <= k)
	while(i < obj->count)
	(obj->val1)[i] += val, i++;
	
	else
	while(i < k)
	(obj->val1)[i] += val, i++; 
}

void customStackFree(CustomStack* obj) 
{
	free(obj);
}

```