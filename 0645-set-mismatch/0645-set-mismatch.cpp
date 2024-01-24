class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int>ans;
        int vis[10002];
        int mx=0;
        memset(vis,0,sizeof(vis));
        for(auto num : nums){
            vis[num]++;
            mx=max(mx,num);
        }
        
        int twice=0,mising=0;
        for(int i=1;i<=mx;i++){
           if(vis[i]>1) twice=i;
            if(vis[i]==0) mising=i;
        }
        cout<<twice<<" "<<mising<<endl;
        if(twice==0) twice++;
        if(mising==0) mising=mx+1;
        ans.push_back(twice);
        ans.push_back(mising);
        cout<<twice<<" "<<mising<<endl;
        return ans;
    }
};