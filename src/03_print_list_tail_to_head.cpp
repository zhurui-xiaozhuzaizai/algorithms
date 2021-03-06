/*
* Copyright(c) 2019 Jiau Zhang
* For more information see <https://github.com/JiauZhang/algorithms>
* 
* This repo is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation
*
* It is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with THIS repo. If not, see <http://www.gnu.org/licenses/>.
*/

/**
*题目描述：
*    输入一个链表，按链表值从尾到头的顺序返回一个ArrayList
*
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };

解题思路：
    1. 因为要从尾到头的顺序，所以这里使用栈的特性，先入后出
    2. 也可以使用递归的形式实现反转，为了实现反转，因此需要先考虑
       当前节点是否存在下一个，如果存在就递归，然后再加入当前节点即可
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        stack<int> vals;
        vector<int> array_list;
        
        while (head) {
            vals.push(head->val);
            head = head->next;
        }
        
        if (vals.size()) {
            while (!vals.empty()) {
                array_list.push_back(vals.top());
                vals.pop();
            }                
        }
        
        return array_list;
    }
};

class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> array_list;
        if (head == NULL)
            return array_list;
        
        if (head->next)
            array_list = printListFromTailToHead(head->next);
        
        array_list.push_back(head->val);
        
        return array_list;
    }
};