/*
 * 方法一：
 * 分别读取L1，L2的值，存入vector<int> vec
 * 对该vec进行升序排序
 * 排序完的值依次存入L3中；
 * /
/* 方法二：
 * 如果L1,L2都存在；
 * 对L1,L2节点依次比较大小，较小的存入L3；
 * 若L1较小，L1存入L3，L1节点后移；
 * 若L2较小，L2存入L3，L2节点后移；
 * 若L1, L2有一个不存在，则将后续节点全部赋值给L3；
 * / 

//方法一：

    vector<int> A;
	ListNode *tempL1 = l1;
	while (tempL1 != nullptr) {
		A.push_back(tempL1->val);
		tempL1 = tempL1->next;
	}
	ListNode *tempL2 = l2;
	while (tempL2 != nullptr) {
		A.push_back(tempL2->val);
		tempL2 = tempL2->next;
	}
	sort(A.begin(), A.end(), less<int>());

	ListNode *l3 = new ListNode(1);
	ListNode *ptr = l3;
	for (auto iter = A.begin(); iter != A.end(); ++iter)
	{
		ListNode *temp = new ListNode(*iter);
		ptr->next = temp;
		ptr = ptr->next;
	}
    return l3->next;



//方法二：

    ListNode *l3 = new ListNode(1);
	ListNode *ptr = l3;
    while (l1 != nullptr && l2 != nullptr)
	{
		if (l1->val <= l2->val) {
			ptr->next = l1;
			ptr = l1;
			l1 = l1->next;
		} else {
			ptr->next = l2;
			ptr = l2;
			l2 = l2->next;
		}
	}
    //关键点：当有其中一个为空，则剩下的链表直接复制给L3；
	ptr->next = (l1 == nullptr ? l2 : l1);
    l3 = l3->next;
    return l3;