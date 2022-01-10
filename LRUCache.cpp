#include<bits/stdc++.h>
using namespace std;

class LRUCache{
	public:
		class Node{
			public:
				int key;
				int val;
				Node* next;
				Node* prev;
				
				Node(int _key,int _val){
					key = _key;
					val = _val;
				}
		};
		
		int capacity;
		Node* head = new Node(-1,-1);
		Node* tail = new Node(-1,-1);
		unordered_map<int,Node*> m;
		
		LRUCache(int size){
			capacity = size;
			head->next = tail;
			tail->prev = head;
		}
		
		void addNode(Node* newNode){
			Node* temp = head->next;
			head->next= newNode;
			newNode->prev = head;
			newNode->next = temp;
			temp->prev = newNode;
		}
		
		void deleteNode(Node* delNode){
			Node* delPrev= delNode->prev;
			Node* delNext = delNode->next;
			
			delPrev->next = delNext;
			delNext->prev = delPrev;
		}
		
		int get(int _key){
			if(m.find(_key)!=m.end()){
				Node* temp = m[_key];
				int val = temp->val;
				//m.erase(_key);
				deleleNode(temp);
				addNode(temp);
				m[_key] = head->next;
				return val;
			}
			return -1;
		}	
		
		void put(int _key,int _val){
			if(m.find(_key)!=m.end()){
				Node* temp = m[_key];
				deleteNode(temp);
				m.erase(_key);
			}
			
			if(m.size()==capacity){
				Node* temp = tail->prev;
				deleteNode(temp);
				m.erae(temp->val);
			}
			
			Node* newNode = new Node(_key,_val);
			addNode(newNode);
			m[_key] = head->next;
		}
	
	
};
int main(){
	int n;
	cin<<n;
	
	LRUCache *o = new LRUCache(n);
	
	
}

