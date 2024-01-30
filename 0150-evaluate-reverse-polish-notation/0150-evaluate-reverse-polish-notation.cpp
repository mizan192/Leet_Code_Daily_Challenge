#define ll long long int
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n=tokens.size();
        stack <ll> s;
        for(int i=0;i<n;i++){
            if(tokens[i]=="+"){
                ll a=s.top();
                s.pop();
                ll b=s.top();
                s.pop();
                s.push(a+b);
            }
            else if(tokens[i]=="-"){
                ll a=s.top();
                s.pop();
                ll b=s.top();
                s.pop();
                s.push(b-a);
            }
            else if(tokens[i]=="*"){
                ll a=s.top();
                s.pop();
                ll b=s.top();
                s.pop();
                s.push(a*b);
            }
            else if(tokens[i]=="/"){
                ll a=s.top();
                s.pop();
                ll b=s.top();
                s.pop();
                s.push(b/a);
            }
            else{
                s.push(stoi(tokens[i]));
            }
            
        }
        return s.top();
    }
	
};