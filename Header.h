namespace MYNAMESPACE
{

	class bookshope 
	{
		public:
		void control_panel();   
		void add_book();        
		void show_book();
		void check_book();
	
	};

	class Update : public bookshope
	{
		public :

		void del_book();
		void update_book();
		void buy_book();
	
	};

}