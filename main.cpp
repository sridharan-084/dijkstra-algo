class Solution
        {
        public:
            //Function to find the shortest distance of all the vertices
            //from the source vertex S.
            vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
            {
                vector<int>dis(V+1 , INT_MAX);
                vector<bool>fil(V+1 , false);
                dis[S] = 0;
                set<pair<int , int>>s;
                //[currdis , node]//
                s.insert({0, S});

                while (!s.empty()){

                    auto it = s.begin();
                    int parent = it->second;
                    dis[parent] = it->first;
                    fil[parent] = true;
                    s.erase(it);
                    for (auto x : adj[parent]){

                        int child = x[0];
                        int weight = x[1];

                        if (!fil[child] && dis[child] > dis[parent] + weight){
                            auto it = s.find({dis[child] , child});
                            if ( it != s.end()){
                                s.erase(it);
                            }
                            dis[child] = dis[parent] + weight;
                            s.insert({dis[child] , child});
                        }
                    }
                }
                return dis;
            }
        };