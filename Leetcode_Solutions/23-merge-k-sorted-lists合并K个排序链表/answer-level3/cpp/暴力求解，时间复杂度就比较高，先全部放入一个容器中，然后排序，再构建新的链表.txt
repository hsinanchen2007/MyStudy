#pragma once
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct ListNode {
	int val;
  ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
class Solution {
public:
	ListNode * mergeKLists(vector<ListNode*>& lists) {
		if (lists.size() == 0) { return NULL; }
		vector<int>str;
		for (int i = 0; i < lists.size(); i++) {
			while (lists[i] != NULL) {
				str.push_back(lists[i]->val);
				lists[i] = lists[i]->next;
			}
		}
		if (str.size() == 0)return NULL;
		sort(str.begin(), str.end());
		ListNode *p = new ListNode(str[0]);
		ListNode *q = new ListNode(str[0]);
		q = p;
		for (int j = 1; j < str.size(); j++) {
		p->next= new ListNode(str[j]);
		p = p->next;
		}
		return q;
	}
};