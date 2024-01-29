class MyQueue {
public:
 stack<int>st1,st2;


    MyQueue() {
       
    }
    
    void push(int x) {
        st1.push(x);
        //return 0;
    }
    
    int pop() {
        vector<int>v;
        int top=st1.top();
        int len =st1.size();
        while(!st1.empty()){
            top=st1.top();
            st1.pop();
            v.push_back(top);
        }

        for(int i=len-2;i>=0;i--) st1.push(v[i]);
        return v[len-1];
    }
    
    int peek() {
        vector<int>v;
        int top=st1.top();
        int len =st1.size();
        while(!st1.empty()){
            top=st1.top();
            st1.pop();
            v.push_back(top);
        }

        for(int i=len-1;i>=0;i--) st1.push(v[i]);
        return v[len-1];
    }
    
    bool empty() {
        if(st1.size()==0) return 1;
        else return 0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */