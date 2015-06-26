/*
 * Copyright (c) 2013, 2014, 2015 Corvusoft
 */

#ifndef _RESTBED_DETAIL_SOCKET_IMPL_H
#define _RESTBED_DETAIL_SOCKET_IMPL_H 1

//System Includes
#include <chrono>
#include <string>
#include <memory>
#include <functional>

//Project Includes

//External Includes
#include <asio.hpp>
#include <asio/ssl.hpp>
#include <corvusoft/framework/byte>

//System Namespaces

//Project Namespaces

//External Namespaces

namespace restbed
{
    //Forward Declarations
    class Session;
    
    namespace detail
    {
        //Forward Declarations
        
        class SocketImpl
        {
            public:
                //Friends
                
                //Definitions
                
                //Constructors
                SocketImpl( const std::shared_ptr< asio::ip::tcp::socket >& socket );

                SocketImpl( const std::shared_ptr< asio::ssl::stream< asio::ip::tcp::socket > >& socket );
                
                virtual ~SocketImpl( void );
                
                //Functionality
                void close( void );

                bool is_open( void ) const;
                
                bool is_closed( void ) const;

                void wait( const std::chrono::microseconds& delay, const std::function< void ( const asio::error_code & ) >& callback );

                void write( const framework::Bytes& data, const std::function< void ( const asio::error_code&, std::size_t ) >& callback );

                void read( const std::shared_ptr< asio::streambuf >& data, const std::size_t length, const std::function< void ( const asio::error_code&, std::size_t ) >& callback );

                void read( const std::shared_ptr< asio::streambuf >& data, const std::string& delimiter, const std::function< void ( const asio::error_code&, std::size_t ) >& callback );

                //Getters
                std::string get_local_endpoint( void ) const;

                std::string get_remote_endpoint( void ) const;
                
                //Setters

                //Operators
                
                //Properties
                
            protected:
                //Friends
                
                //Definitions
                
                //Constructors
                
                //Functionality
                
                //Getters
                
                //Setters
                
                //Operators
                
                //Properties
                
            private:
                //Friends
                
                //Definitions
                
                //Constructors
                SocketImpl( const SocketImpl& original ) = delete;

                //Functionality

                //Getters
                
                //Setters
                
                //Operators
                SocketImpl& operator =( const SocketImpl& value ) = delete;
                
                //Properties
                bool m_is_open;

                std::shared_ptr< asio::steady_timer > m_timer;

                std::shared_ptr< asio::ip::tcp::socket > m_socket;

                std::shared_ptr< asio::ssl::stream< asio::ip::tcp::socket > > m_ssl_socket;
        };
    }
}

#endif  /* _RESTBED_DETAIL_SOCKET_IMPL_H */