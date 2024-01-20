#define ll long long int
#define MOD 1000000007

class Solution {
public:

	int sumSubarrayMins(vector<int>& arr) {

		int n = arr.size();

		vector<int> l(n), r(n);


		stack<int>lst;
		lst.push(0);

		l[0] = 1;

		for (int i = 1; i < n; i++)
		{
			while (!lst.empty() && arr[i] < arr[lst.top()])
				lst.pop();

			if (lst.empty())
				l[i] = i + 1; // total distance if less element not found = i+1
			else
				l[i] = i - lst.top(); // distance = i-lst.top()

			lst.push(i);

		}



		stack<int>r_st;
		r_st.push(n - 1);

		r[n - 1] = 1;

		for (int i = n - 2; i >= 0; i--)
		{
			while (!r_st.empty() && arr[i] <= arr[r_st.top()])
				r_st.pop();

			if (r_st.empty())
				r[i] = n - i; // distance
			else
				r[i] = r_st.top() - i;

			r_st.push(i);
		}

	
	ll res = 0;
		for (int i = 0; i < n; i++)
		{
	ll prod = (l[i] * r[i]) % MOD;
			ll net = arr[i] * prod;
			res = (res + net) % MOD;
		}

		return res % MOD;
	}

};