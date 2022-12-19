超简单，不需要什么heap，直接全部读出来，排序，然后重新连一遍就好了。
```
ListNode* mergeKLists(vector<ListNode*>& lists) {
    vector<ListNode*> longList;
    for (ListNode* start:lists){
        ListNode* ptr = start;
        while (ptr != NULL){
            longList.push_back(ptr);
            ptr = ptr->next;
        }
    }
    std::sort(longList.begin(),longList.end(),[](auto x,auto y){return ((x->val) < (y->val));});
    if (longList.size() ==0){return NULL;}
    for (size_t i=0;i<longList.size()-1;i++){
        longList[i]->next = longList[i+1];
    }
    longList[longList.size()-1]->next = NULL;
    return longList[0];
}
```
